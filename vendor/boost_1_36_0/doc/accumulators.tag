<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="struct">
    <name>boost::accumulators::extractor</name>
    <filename>structboost_1_1accumulators_1_1extractor.html</filename>
    <templarg>Feature</templarg>
    <member kind="typedef">
      <type>extractor&lt; Feature &gt;</type>
      <name>this_type</name>
      <anchorfile>structboost_1_1accumulators_1_1extractor.html</anchorfile>
      <anchor>554f534b7b0d9cb5d8235b35180991a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>detail::extractor_result&lt; Arg1, Feature &gt;::type</type>
      <name>operator()</name>
      <anchorfile>structboost_1_1accumulators_1_1extractor.html</anchorfile>
      <anchor>92fe5489e0a5dfa1ea4419a5dbefa896</anchor>
      <arglist>(Arg1 const &amp;arg1) const </arglist>
    </member>
    <member kind="function">
      <type>detail::extractor_result&lt; AccumulatorSet, Feature &gt;::type</type>
      <name>operator()</name>
      <anchorfile>structboost_1_1accumulators_1_1extractor.html</anchorfile>
      <anchor>05e7c9e13d4babcf67d56cec81b9aef9</anchor>
      <arglist>(AccumulatorSet const &amp;acc, A1 const &amp;a1) const </arglist>
    </member>
    <member kind="function">
      <type>detail::extractor_result&lt; AccumulatorSet, Feature &gt;::type</type>
      <name>operator()</name>
      <anchorfile>structboost_1_1accumulators_1_1extractor.html</anchorfile>
      <anchor>b8cc41473776d459ad107043e796c08e</anchor>
      <arglist>(AccumulatorSet const &amp;acc, A1 const &amp;a1, A2 const &amp;a2,...)</arglist>
    </member>
    <class kind="struct">boost::accumulators::extractor::result&lt; this_type(A1)&gt;</class>
  </compound>
  <compound kind="struct">
    <name>boost::accumulators::depends_on</name>
    <filename>structboost_1_1accumulators_1_1depends__on.html</filename>
    <templarg>Feature1</templarg>
    <templarg>Feature2</templarg>
    <templarg></templarg>
    <member kind="typedef">
      <type>mpl::false_</type>
      <name>is_weight_accumulator</name>
      <anchorfile>structboost_1_1accumulators_1_1depends__on.html</anchorfile>
      <anchor>985b688e224c7ee167d28f42d930a257</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>mpl::transform&lt; mpl::vector&lt; Feature1, Feature2,...&gt;, as_feature&lt; mpl::_1 &gt; &gt;::type</type>
      <name>dependencies</name>
      <anchorfile>structboost_1_1accumulators_1_1depends__on.html</anchorfile>
      <anchor>c27dba2ed95ab1c424261048a4604b22</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
