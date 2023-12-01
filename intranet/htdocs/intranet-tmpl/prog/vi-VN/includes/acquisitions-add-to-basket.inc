<fieldset class="acqui_basket_add">
 <legend class="sr-only">Tạo đơn hàng</legend>
 [% IF has_budgets %]
 <ul>
 <li>
 <form action="/cgi-bin/koha/catalogue/search.pl" method="get">
 <label>Từ biểu ghi hiện tại: <input type="text" name="q" size="25" />
 </label>
 <input class="submit" data-basketno="[% basketno | html %]" data-booksellerid="[% booksellerid | html %]" id="searchtoorder" type="submit" value="Tìm kiếm" />
 </form>
 </li>
 <li><a href="/cgi-bin/koha/acqui/newordersuggestion.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Từ đề xuất mua</a></li>
 <li><a href="/cgi-bin/koha/acqui/newordersubscription.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Từ ÂPĐK</a></li>
 <li><a href="/cgi-bin/koha/acqui/neworderempty.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Từ biểu ghi mới</a></li>
 <li><a href="/cgi-bin/koha/acqui/duplicate_orders.pl?basketno=[% basketno | uri %]">From existing orders (copy)</a></li>
 <li><a href="/cgi-bin/koha/acqui/z3950_search.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Từ Z39.50</a></li>
 [% IF ( CAN_user_tools_stage_marc_import ) %]<li><a href="/cgi-bin/koha/tools/stage-marc-import.pl?basketno=[% basketno | uri %]&amp;booksellerid=[% booksellerid | uri %]"> From a new file</a></li>[% END %]
 <li><a href="/cgi-bin/koha/acqui/addorderiso2709.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]"> Từ tệp tin</a></li>
 [% IF ( CAN_user_circulate ) %]<li><a href="/cgi-bin/koha/circ/reserveratios.pl?booksellerid=[% booksellerid | uri %]&amp;basketno=[% basketno | uri %]">Từ nhan đề có tỷ lệ đặt mượn cao nhất</a></li>[% END %]
 </ul>
 [% ELSE %]
 <div class="dialog alert">
 <p>Bạn không thể tạo đơn hàng. Bạn cần phải <a href="/cgi-bin/koha/admin/aqbudgetperiods.pl">tạo quỹ hoặc ngân sách</a>.</p>
 </div>
 [% END %]
</fieldset>
